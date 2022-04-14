

JAVA_HOME=/usr/lib/jvm/java-11-openjdk-11.0.13.0.8-2.fc33.x86_64/


all: com/abcd/jni/HelloWorldJNI.class libnative.so 

#com/abcd/jni/Simple.class: com/abcd/jni/Simple.java
#	javac com/abcd/jni/Simple.java

com/abcd/jni/HelloWorldJNI.class: com/abcd/jni/HelloWorldJNI.java
	javac -h . com/abcd/jni/HelloWorldJNI.java

HelloWorldJNI.o: HelloWorldJNI.c
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux HelloWorldJNI.c -o HelloWorldJNI.o

libnative.so: HelloWorldJNI.o
	gcc --shared -fPIC -o libnative.so HelloWorldJNI.o -lc

clean : 
	rm -f com/abcd/jni/Simple.class  com/abcd/jni/HelloWorldJNI.class libnative.so HelloWorldJNI.o com_abcd_jni_HelloWorldJNI.h


# Pour executer
# java -cp . -Djava.library.path=. com.abcd.jni.HelloWorldJNI

