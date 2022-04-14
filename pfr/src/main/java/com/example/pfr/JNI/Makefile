

JAVA_HOME=/usr/lib/jvm/java-11-openjdk-11.0.13.0.8-2.fc33.x86_64/


all: ../JNI/JNI.class ../JNI/libJNI.so 

#com/abcd/jni/Simple.class: com/abcd/jni/Simple.java
#	javac com/abcd/jni/Simple.java

../JNI/JNI.class: ../JNI/JNI.java
	javac -h ../JNI ../JNI/JNI.java

#HelloWorldJNI.o: HelloWorldJNI.c
#	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux HelloWorldJNI.c -o HelloWorldJNI.o

../JNI/libJNI.so: ../JNI/JNI.o
	gcc --shared -fPIC -o ../JNI/libJNI.so ../JNI/JNI.o -lc

clean : 
	rm -f ../JNI/JNI.class ../JNI/libJNI.so ../JNI/JNI_JNI.h


# Pour executer dans le repertoire JNI
# java -cp .. -Djava.library.path=../JNI JNI/JNI

# Pour executer dans ../test
# java -cp .. -Djava.library.path=../JNI JNI.JNI
