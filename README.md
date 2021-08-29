# Uni_CyberSec
A small very basic piece of malware and the code to remove the changes the malware makes written in C++

Purpose:
-----------------------------------------------------------------
The purpose of this code is to showcase how viruses and malware can infect the windows registry, this code will simply create a new registry key called 'MSPaint', it has no function and is just there as an example.

How to remove:
-----------------------------------------------------------------
You can remove the registry via the anti-virus included, or you can manually delete the registry stored in:
Computer\HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
