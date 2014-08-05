#include "StdAfx.h"
#include "GPSForm.h"

using namespace HelloGPSWorld;
using namespace System::IO::Ports;

//Find Ports code
void GPSForm::FindPorts(void) 
{
	// Get port names
	array<Object^>^ objectArray = SerialPort::GetPortNames();
	// Add string array to combobox
	this->cbComPort->Items->AddRange( objectArray );
}

void GPSForm::handleGPSOutput(String^ gpsLine /*, timestamp */) 
{
	// Parse the GPS NMEA sentence. Update the relevant displays, and write the useful sentences to the data file with a timestamp

	// First, carve off the first token and determine what we should do with it.
	array<String^>^ words;
	words = gpsLine->Split(',');
	int numWords = words->Length;

	if(numWords > 0) {
		if(words[0] == "$GPGGA") { // Standard position sentence
			// Update Latitude
			try { 
				String^ temp = String::Empty;
				double latitude = Convert::ToDouble(words[2]);
				int latdeg = (int) (latitude/100.0);
				temp = latdeg.ToString("00");
				temp+= "°"; // hold down ALT, type 248
				latitude = latitude - latdeg*100;
				temp += latitude.ToString(".0000");

				this->tbLatitude->Text = temp;
			} catch (Exception^) {
				this->tbLatitude->Text = "No fix.";
			}

			// Update Longitude
			try {
				String^ temp = String::Empty;
				double longitude = Convert::ToDouble(words[4]);
				int londeg = (int) (longitude/100.0);
				temp = londeg.ToString("00");
				temp+= "°"; // hold down ALT, type 248
				longitude = longitude - londeg*100;
				temp+= longitude.ToString(".0000");
				this->tbLongitude->Text = temp;
			} catch (Exception^) {
				this->tbLongitude->Text = "No fix.";
			}
			// Update Altitude
			this->tbAltitude->Text = words[9];

			// Update Altitude Units
			this->tbAltitudeUnits->Text = words[10];
			this->rtbGPSOutput->AppendText(Convert::ToString(numWords));
			for(int i=0; i<numWords; i++) {
				this->rtbGPSOutput->AppendText(" ");
				this->rtbGPSOutput->AppendText(words[i]);
			}
			//this->rtbGPSOutput->AppendText(gpsLine);
		} else if(words[0] == "$GPRMC") { // Minimum sentence with velocity
			// Word[7] is velocity in knots, word 8 is direction

			try {
				double speed = Convert::ToDouble(words[7]);
				speed *= 1.15077945; // convert from knots to mph
				tbSpeedMPH->Text = speed.ToString("0.0");
				speed *= 3600.0/5280.0; // convert from mph to feet/sec
				tbSpeedF_S->Text = speed.ToString("0.0");
				speed *= 0.3048; // convert from feet/sec to meters/sec
				tbSpeedM_S->Text = speed.ToString("0.0");
				tbHeading->Text = words[8];
			} catch (Exception^) {
				tbSpeedMPH->Text = "No fix.";
				tbSpeedF_S->Text = String::Empty;
				tbSpeedM_S->Text = String::Empty;
				tbHeading->Text = String::Empty;
			}

			//this->rtbGPSOutput->AppendText(gpsLine);
		}
	}
}