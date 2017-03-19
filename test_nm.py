###### install pi.test pour utiliser le fichier de test
import sys
import os
import subprocess

def test_myoutput1(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm ls")
	str2 = os.system("nm ls")
	assert str1 == str2