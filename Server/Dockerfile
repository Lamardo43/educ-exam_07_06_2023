FROM ubuntu:18.04

LABEL author="Klim Medvedev"

ENV TZ=Europe/Moscow    
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone   
 
RUN apt-get update    
RUN apt-get install qt5-default -y    
RUN apt-get install qtbase5-dev -y    
RUN apt-get install qt5-qmake    
RUN apt-get install build-essential -y

WORKDIR /root/
RUN mkdir Medvedev_221-329

WORKDIR /root/Medvedev_221-329

COPY *.cpp /root/Medvedev_221-329
COPY *.h /root/Medvedev_221-329
COPY *.pro /root/Medvedev_221-329

RUN qmake hallServer.pro
RUN make hallServer

ENTRYPOINT ["./hallServer"]