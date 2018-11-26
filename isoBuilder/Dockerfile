FROM alpine:3.8

RUN apk add --no-cache gcc g++ binutils grub grub-bios make xorriso

RUN mkdir -p /usr/src/app

WORKDIR /usr/src/app/

CMD [ "make", "mykernel.iso" ]
