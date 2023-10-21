set pagination off
<<<<<<< HEAD
symbol-file zephyr/zephyr.elf
target remote 127.0.0.1:1234
=======
#symbol-file build/zephyr/zephyr.elf
target remote :5678
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
b test
b main.c:33
c

s
set var a = 2
c
if ret == 6
	printf "PASSED\n"
	quit 0
else
	printf "FAILED\n"
	quit 1
end
