#include "SpectralRadar.h"
#include "OCT.h"
#include <iostream> 

using namespace std;

void SyncAcquisition()
{
	OCTDeviceHandle Dev = initDevice();
	ProbeHandle Probe = initProbe(Dev, "Probe");
	ProcessingHandle Proc = createProcessingForDevice(Dev);

	ScanPatternHandle Pattern = createBScanPattern(Probe, 2.0, 2048, TRUE);

	RawDataHandle Raw = createRawData();
	DataHandle BScan = createData();
	ColoredDataHandle ColoredBScan = createColoredData();
	ComplexDataHandle ComplexBScan = createComplexData();

	Coloring32BitHandle Color = createColoring32Bit(ColorScheme_BlackAndWhite, Coloring_RGBA);

	setColoringBoundaries(Color, 0.0f, 70.0f);
	startMeasurement(Dev, Pattern, Acquisition_Sync);

	while (!_kbhit())
	{
		getRawData(Dev, Raw);

		int SizeX, SizeY, SizeZ;
		getRawDataSize(Raw, &SizeX, &SizeY, &SizeZ);

		setProcessedDataOutput(Proc, BScan);

		executeProcessing(Proc, Raw);
		

		exportData2DAsImage(BScan, Color, ColoredDataExport_BMP, "..\\test\\test.bmp", FALSE, FALSE, TRUE);
		char error[512];
		if (getError(error, 512))
		{
			_getch();
		}
	}
	stopMeasurement(Dev);

	clearRawData(Raw);
	clearData(BScan);
	clearScanPattern(Pattern);
	closeProbe(Probe);
	closeDevice(Dev);
}


void AdvancedSnapshotTest()
{
	char message[512];

	OCTDeviceHandle Dev = initDevice();

	if (getError(message, 512))
	{
		cerr << "\n\n" << message << endl;
		_getch();
		return;
	}

	const int size_z = getDevicePropertyInt(Dev, DevicePropertyInt::Device_SpectrumElements) / 2;
	const int size_x = 512;
	const int size_y = 10;

	ProbeHandle Probe = initProbe(Dev, "Probe");
	ProcessingHandle Proc = createProcessingForDevice(Dev);

	ScanPatternHandle Pattern = createBScanStackPattern(Probe, 5.0, size_x, 0.0, size_y);

	DataHandle BScan = createData();
	RawDataHandle Raw = createRawData();
	DataHandle Volume = createData();
	reserveData(Volume, size_z, size_x, size_y);
	Coloring32BitHandle coloring = createColoring32Bit(ColorScheme_BlackAndWhite, Coloring_BGRA);

	startMeasurement(Dev, Pattern, Acquisition_AsyncFinite);
	for (int i = 0; i < size_y; ++i)
	{
		getRawData(Dev, Raw);
		setProcessedDataOutput(Proc, BScan);
		executeProcessing(Proc, Raw);

		appendData(Volume, BScan, Direction_3);

		cout << "BScan Size: " << getDataPropertyFloat(BScan, Data_Range1) << " x " << getDataPropertyFloat(BScan, Data_Range2) << endl;

		if (getError(message, 512))
		{
			cerr << "\n\nAn error occurred: " << message << endl;
			_getch();
		}
	}
	crossCorrelatedProjection(Volume, BScan);
	float min_dB, max_dB;
	determineDynamicRange(BScan, &min_dB, &max_dB);
	setColoringBoundaries(coloring, min_dB, max_dB);
	exportData2DAsImage(BScan, coloring, ColoredDataExport_PNG, "C:/Users/OCT/Desktop/Project/three/MFC_OCT/test/AdvancedSnapshot.png", false, false, false);

	stopMeasurement(Dev);

	clearRawData(Raw);
	clearData(BScan);
	clearData(Volume);
	clearScanPattern(Pattern);
	closeProbe(Probe);
	closeProcessing(Proc);
	closeDevice(Dev);

	_getch();
	if (getError(message, 512))
	{
		cerr << "\n\nAn error occurred: " << message << endl;
		_getch();
	}
}