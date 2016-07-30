run: solution.c lib
	gcc solution.c -ldl -o solution

lib: shared.c
	gcc shared.c -fPIC -shared -o libShared.so

clean:
	-rm libShard.so run 2>/dev/null
