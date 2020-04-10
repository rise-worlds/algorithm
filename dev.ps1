$env:Path += ";${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\"
$installPath = vswhere -version 16.0 -prerelease -property installationpath
Import-Module (Join-Path $installPath "Common7\Tools\vsdevshell\Microsoft.VisualStudio.DevShell.dll")
Enter-VsDevShell -VsInstallPath $installPath -SkipAutomaticLocation
code ./

# "C:\Program Files\PowerShell\6\pwsh.exe" -noe -c "&{Import-Module """C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"""; Enter-VsDevShell a4017e9f -SkipAutomaticLocation}"