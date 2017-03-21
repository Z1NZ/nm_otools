import sys
import os
import subprocess

def test_myoutput1(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/test_64")
	str2 = os.system("nm ./nm-otool-tests/test_64")
	assert str1 == str2

def test_myoutput2(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/64_exe_easy")
	str2 = os.system("nm ./nm-otool-tests/64_exe_easy")
	assert str1 == str2

def test_myoutput3(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/64_exe_medium")
	str2 = os.system("nm ./nm-otool-tests/64_exe_medium")
	assert str1 == str2

def test_myoutput3(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/64_exe_hard")
	str2 = os.system("nm ./nm-otool-tests/64_exe_hard")
	assert str1 == str2

def test_myoutput4(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/64_lib_dynamic_medium")
	str2 = os.system("nm ./nm-otool-tests/64_lib_dynamic_medium")
	assert str1 == str2

def test_myoutput5(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/64_lib_dynamic_hard")
	str2 = os.system("nm ./nm-otool-tests/64_lib_dynamic_hard")
	assert str1 == str2

def test_myoutput6(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/64_bundle")
	str2 = os.system("nm ./nm-otool-tests/64_bundle")
	assert str1 == str2

def test_myoutput7(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/32_exe_hard")
	str2 = os.system("nm ./nm-otool-tests/32_exe_hard")
	assert str1 == str2

def test_myoutput8(capsys):
	str1 = os.system("./ft_nm ./nm-otool-tests/test_32")
	str2 = os.system("nm ./nm-otool-tests/test_32")
	assert str1 == str2
