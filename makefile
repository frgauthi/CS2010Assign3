cc = g++
obj = dictionary.o
bin = dictionary

$(bin): $(obj)
	$(cc)  $(obj) -o $(bin)

.cpp.o:
	$(cc) -c  $<

clean: 
	rm *.o $(bin)
