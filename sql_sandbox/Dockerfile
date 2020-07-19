FROM postgres:latest
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get install -y build-essential cmake clang libssl-dev vim openssh-server iputils-ping net-tools

RUN mkdir /src
RUN mkdir /var/run/sshd

RUN echo 'root:root' | chpasswd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin prohibit-password/' /etc/ssh/sshd_config
RUN sed -i 's/#Port 22/Port 20022/' /etc/ssh/sshd_config
COPY ./id_rsa.pub /root/.ssh/authorized_keys

WORKDIR /src

EXPOSE 5432
EXPOSE 20022
CMD ["/usr/sbin/sshd", "-D"]