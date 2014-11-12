cc = g++
obj = dictionary.o
obj2 = main.o
bin = dictionary

$(bin): $(obj) $(obj2)
	$(cc)  $(obj2) $(obj) -o $(bin)

.cpp.o:
	$(cc) -c  $<

clean: 
	rm *.o $(bin)
