fqbn = arduino:avr:uno
tty = /dev/ttyUSB0

build:
	mkdir -p out
	mkdir -p out/build
	arduino-cli compile --fqbn $(fqbn) --build-path out

run: build
	arduino-cli upload -p $(tty) --fqbn $(fqbn) --input-dir out

tty: run
	screen $(tty) 9600 # exit with C-a C-k
