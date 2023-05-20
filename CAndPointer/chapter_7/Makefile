obj = work
$(obj) : $(obj).o
	-gcc -o $(obj)  $(obj).o
	-rm *.o

$(obj).o : $(obj).c
	-gcc -c $(obj).c

.PHONY : clean

clean : 
	-rm $(obj)