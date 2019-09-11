$env:Path += ";${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\"
$installPath = vswhere -version 16.0 -prerelease -property installationpath
Import-Module (Join-Path $installPath "Common7\Tools\vsdevshell\Microsoft.VisualStudio.DevShell.dll")
Enter-VsDevShell -VsInstallPath $installPath -SkipAutomaticLocation
code ./