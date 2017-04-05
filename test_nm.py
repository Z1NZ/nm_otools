import sys
import os
import subprocess

def test_myoutput1(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/test_64", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/test_64", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput2(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/64_exe_easy", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/64_exe_easy", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput3(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/64_exe_medium", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/64_exe_medium", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput3(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/64_exe_hard", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/64_exe_hard", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput4(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/64_lib_dynamic_medium", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/64_lib_dynamic_medium", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput5(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/64_lib_dynamic_hard", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/64_lib_dynamic_hard", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput6(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/64_bundle", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/64_bundle", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput7(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/32_exe_hard", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/32_exe_hard", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput8(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/object_easy", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/object_easy", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput9(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/object_medium", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/object_medium", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput10(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/fat_hard", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/fat_hard", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput11(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/error", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/error", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2
