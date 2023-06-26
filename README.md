<div align="center">
  <img align="center" src=".github/images/flipper-dev.png" />
  <h2 align="center">Flipper Zero Windows Development</h2>
  <p align="center">
    This guide provides a quick start for developing Flipper Zero firmware and applications on Windows using Visual Studio Code. It is a compilation of information from the official Flipper Zero documentation and various other sources.
  </p>
  <a href="https://shop.flipperzero.one/">
    <img src=".github/images/flipper-zero-buy-now.svg" />
  </a>
  <a href="https://docs.flipperzero.one/">
    <img src=".github/images/flipper-zero-docs.svg" />
  </a>
  <p align="center">
    <b>Disclaimer</b>: This is not an official guide endorsed by the Flipper Zero team. It is a personal guide created to assist in Flipper Zero development on Windows. The author is not liable for any damage caused to your device or computer. Use it at your own risk.
  </p>
</div>

---

## Table of Contents <a name="index"></a>

- [Firmware Development & Setup](#firmware-development)
- [Building and Flashing Firmware](#building-and-flashing-firmware)
- [Application Development](#application-development)
- [Build and Upload Application](#build-and-upload-app)

## Firmware Development (and Application Development Pre-Setup) <a name="firmware-development"></a>

1. Install the following prerequisites:

   - [GIT](https://git-scm.com/downloads)
   - [Visual Studio Code](https://code.visualstudio.com/download)
   - [Python](https://www.python.org/downloads/)

2. Open a command terminal as an administrator:

   - Press ⊞Win+R, type "cmd", and press CTRL+SHIFT+ENTER.

3. Navigate to the folder where you want to develop:

   ```
   cd X:\Development
   ```

4. Clone the [Flipper Zero][flipper-zero] firmware repository you want to work with (options [here](https://github.com/UberGuidoZ/Flipper/tree/main/Firmware_Options)):

   ```
   git clone https://github.com/flipperdevices/flipperzero-firmware.git
   ```

5. Change directory to the cloned firmware repository:

   ```
   cd flipperzero-firmware
   ```

6. Download the Windows toolchain and set up Visual Studio Code files:

   ```
   fbt vscode_dist
   ```

   This command will download the Windows Toolchain. It may take a few minutes to complete.

7. Check that the command line now shows "(fbt)" indicating the [Flipper Build Tool][flipper-zero-build-tool] entry point has been invoked.

8. Open Visual Studio Code:

   - Click "File" in the top menu and select "Open Folder...".
   - Choose the firmware folder you cloned and click "Select Folder".

9. Install the necessary extensions:

   - Click "View" in the top menu and select "Extensions".
   - Install all recommended extensions for this project.
   - Disable or uninstall any "CMake" related extensions specific to this project.

10. In the command terminal (still within the firmware directory), checkout the branch you want to work on or create a new branch:

    ```
    git checkout release
    ```

11. In Visual Studio Code make your changes to the code, build, and flash the firmware to your device (see [Building and Flashing Firmware](#building-and-flashing-firmware)). Fin.

<p align="right">[ <a href="#index">Back to top</a> ]</p>

## Building and Flashing Firmware <a name="building-and-flashing-firmware"></a>

1. Build the firmware in Visual Studio Code:

   - Click "Terminal" in the top menu and select "Run Task...".
   - Choose "Build" from the list of tasks.

2. Flash the firmware to your Flipper Zero device:
   - Connect your Flipper Zero device to your computer via USB.
   - Click "Terminal" in the top menu and select "Run Task...".
   - Choose "Flash (USB, with resources)" from the list of tasks.

<p align="right">[ <a href="#index">Back to top</a> ]</p>

## Application Development <a name="application-development"></a>

1. Follow the [Firmware Development](#firmware-development) steps above to set up your development environment.

2. Open the firmware folder you cloned in Visual Studio Code.

3. Open a terminal in the firmware folder and run the following code to instantiate the Flipper Build Tool (fbt) entry point:

   ```
   fbt
   ```

   This command may take a few minutes to complete. Once it's finished, the command line will show "(fbt)" indicating that the [Flipper Build Tool][flipper-zero-build-tool] entry point has been invoked.

4. Create a new application folder in the "applications_user" directory. Give it a unique and descriptive name. This is where you will develop your application.

5. To get a good understanding of what you can do with your application, you can copy the contents of the [boilerplate application][boilerplate-app] into your new application folder. For example, I will name my application folder "test."

6. Open the "applications_user\test" directory in Visual Studio Code and start working on your application.

7. Save your changes. Connect your [Flipper Zero][flipper-zero] device to your computer via USB. In the terminal, enter the following command to connect to it using the fbt CLI tool and run your application:

   ```
   fbt launch_app APPSRC=applications_user/test
   ```

   This command will build and run your application on your device. You can now test it out.

8. Once you're happy with the application you can build and upload it to your device (see [Build and Upload Application](#build-and-upload-app)).

<p align="right">[ <a href="#index">Back to top</a> ]</p>

## Build and Upload Application <a name="build-and-upload-app"></a>

1. Connect your [Flipper Zero][flipper-zero] device to your computer via USB.

2. Open a terminal in the firmware folder with fbt instantiated (see [Application Development](#application-development)).

3. Enter the following command to build and upload your application to your device. Replace `{application-folder-name}` with the name of your application folder. Replace `application-id` with the application name you used in `application.fam`:

   ```
   fbt fap_{application-id} APPSRC=applications_user/{application-folder-name}
   ```

   This command will build and upload your application over USB. It may take a few minutes to complete.

4. Alternatively enter the following command to build and deploy all applications (including yours) to your [Flipper Zero][flipper-zero] device:

   ```
   fbt fap_deploy
   ```

   This command will build your application and upload it over USB. It may take a few minutes to complete.

5. Once the command is finished, find your application in the "Applications" menu on your [Flipper Zero][flipper-zero] device within the "Misc" folder.

<p align="right">[ <a href="#index">Back to top</a> ]</p>

Fin. Thanks for looking and happy programming friend!

Cody

<!-- LINKS -->

[flipper-zero]: https://flipperzero.one/
[boilerplate-app]: https://github.com/leedave/flipper-zero-fap-boilerplate
[flipper-zero-build-tool]: https://github.com/flipperdevices/flipperzero-firmware/blob/dev/documentation/fbt.md
[flipper-zero-docs]: https://docs.flipperzero.one/
