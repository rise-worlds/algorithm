#$curpath = $PSScriptRoot
$env:Path+=";${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\"
$installPath = vswhere -version 16.0 -prerelease -property installationpath
Import-Module (Join-Path $installPath "Common7\Tools\vsdevshell\Microsoft.VisualStudio.DevShell.dll")
$null = Enter-VsDevShell -VsInstallPath $installPath -SkipAutomaticLocation -InstanceId a4017e9f 
#Set-Location $curpath