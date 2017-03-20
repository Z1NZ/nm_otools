###### install pi.test pour utiliser le fichier de test
import sys
import os
import subprocess

def test_myoutput1(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm")
	str2 = os.system("nm ")
	assert str1 == str2

def test_myoutput2(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm ./nm-otool-tests/64_exe_easy")
	str2 = os.system("nm ./nm-otool-tests/64_exe_easy")
	assert str1 == str2

def test_myoutput3(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm ./nm-otool-tests/64_exe_medium")
	str2 = os.system("nm ./nm-otool-tests/64_exe_medium")
	assert str1 == str2

def test_myoutput3(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm ./nm-otool-tests/64_exe_hard")
	str2 = os.system("nm ./nm-otool-tests/64_exe_hard")
	assert str1 == str2

def test_myoutput4(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm ./nm-otool-tests/64_lib_dynamic_medium")
	str2 = os.system("nm ./nm-otool-tests/64_lib_dynamic_medium")
	assert str1 == str2

def test_myoutput5(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm ./nm-otool-tests/64_lib_dynamic_hard")
	str2 = os.system("nm ./nm-otool-tests/64_lib_dynamic_hard")
	assert str1 == str2

def test_myoutput6(capsys): # or use "capfd" for fd-level
	str1 = os.system("./ft_nm ./nm-otool-tests/64_bundle")
	str2 = os.system("nm ./nm-otool-tests/64_bundle")
	assert str1 == str2
