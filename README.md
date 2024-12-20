# CBEnroll - Enterprise Chromebook Enrollment (v124.0)

CBEnroll is an Arduino Script built for the Arduino Centipede to aid in mass enrollment for Chromebooks running on ChromeOS v124.0+.

## Installation

1. Use the release package to install the latest release to your local computer. 

2. Install the [Arduino Cloud Agent](https://cloud.arduino.cc/download-agent/) to your local computer.

3. Go to the [Arduino Cloud Editor](https://app.arduino.cc/) or install the [Arduino IDE](https://www.arduino.cc/en/software) and sign-in or create an account.

#### IDE:
Copy the local script package folder to the Sketchbook directory and open the sketch. See [Documentation](https://support.arduino.cc/hc/en-us/articles/4412950938514-Open-the-Sketchbook-folder) for help.

#### Cloud Editor:
**Create New > Sketch > Import File > Select Header.h and cbenroll-v124.ino**. See [Documentation](https://docs.arduino.cc/arduino-cloud/cloud-editor/import-your-sketchbook-and-libraries-to-the-web-editor/) for help.

### SEE USAGE SECTION BEFORE CONTINUING

4. Plug Centipede into computer and select the device on COM port.
5. Upload files to Centipede and remove when done.

## Usage
You will need to edit the [header.h](https://github.com/bradybutcher/cbenroll-v124/blob/main/Chromebook-Enrollment/header.h) file before uploading.

This is the only section (Lines 11-12) you will need to modify for your district's needs. Replace the "----" with "your-enrollmentacc@your-domain" and the password for that account.
```c
#define username "----" // Define the user name for enrolling the device.
#define password "----" // The password for the enrollment GAFE account.
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Documentation
- [Arduino Micro Board Overview](https://docs.arduino.cc/hardware/micro/)
- [Opening files in Arduino IDE](https://support.arduino.cc/hc/en-us/articles/4412950938514-Open-the-Sketchbook-folder)
- [Importing files to Cloud Editor](https://docs.arduino.cc/arduino-cloud/cloud-editor/import-your-sketchbook-and-libraries-to-the-web-editor/)

## Notes
Please be mindful as this release only supports ethernet setup, as I am working on building Wi-Fi support. 

## License

[Apache License 2.0](https://choosealicense.com/licenses/apache-2.0/)
