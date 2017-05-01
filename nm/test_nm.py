import sys
import os
import subprocess

def test_myoutput0(capsys):
	str1 = subprocess.check_output("nm", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

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
	str1 = "ft_nm: ./nm-otool-tests/error The file was not recognized as a valid object file\n\n"
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/error", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput12(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MachO-OSX-ppc-openssl-1.0.1h", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MachO-OSX-ppc-openssl-1.0.1h", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput13(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MIT_LICENSE", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MIT_LICENSE", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput14(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MachO-OSX-ppc-and-i386-bash", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MachO-OSX-ppc-and-i386-bash", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput15(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MachO-OSX-x64-ls", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MachO-OSX-x64-ls", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput16(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MachO-OSX-x86-ls", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MachO-OSX-x86-ls", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput17(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MachO-iOS-arm1176JZFS-bash", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MachO-iOS-arm1176JZFS-bash", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput18(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MachO-iOS-armv7-armv7s-arm64-Helloworld", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MachO-iOS-armv7-armv7s-arm64-Helloworld", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput19(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/MachO-iOS-armv7s-Helloworld", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/MachO-iOS-armv7s-Helloworld", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput20(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/libSystem.B.dylib", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/libSystem.B.dylib", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput21(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/lib_archive_medium", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/lib_archive_medium", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput22(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/test_32", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/test_32", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput___ch25_bin(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/ch25.bin", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/ch25.bin", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2

def test_myoutput____ALL___(capsys):
	str1 = subprocess.check_output("nm ./nm-otool-tests/*", stderr=subprocess.STDOUT, shell=True)
	str2 = subprocess.check_output("./ft_nm ./nm-otool-tests/*", stderr=subprocess.STDOUT, shell=True)
	assert str1 == str2
