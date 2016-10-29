#include<linux/input.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *device;
	int scancode;

	int opt;
	int usage = -1;

	while ((opt = getopt(argc, argv, "d:s:")) != -1) {
		if (usage == -1) {
			usage = 0;
		}

		if (opt == 1) {
			usage = 1;
			continue;
		}

		switch (opt) {
		case 'd':
			device = optarg;
			break;

		case 's':
			if (sscanf(optarg, "%d", &scancode) == 0) {
				fprintf(stderr, "Couldn't parse scancode: %s", optarg);
				usage = 1;
			}
			break;

		case '?':
			usage = 1;
			break;

		default:
			usage = 1;
			break;
		}
	}

	if (usage != 0) {
		fprintf(stderr, "\nUsage: sysrq -d device -s scancode\n\n");
		fprintf(stderr, "  -d		keyboard event input device\n");
		fprintf(stderr, "  -s		decimal scan code\n");
		fprintf(stderr, "\nExample:\n\n");
		fprintf(stderr, "sysrq -d /dev/input/by-id/usb-Apple_Inc._Apple_Internal_Keyboard___Trackpad_XXXXXX-if01-event-k -s 458979\n\n");
		fprintf(stderr, "458979 (0x700e3) is the scancode obtained for the left cmd key\n");
		fprintf(stderr, "You can get getscancodes source at: http://keytouch.sourceforge.net/dl-getscancodes.php\n");
		return 1;
	}

	int codes[2];
	int fd = open(device, O_NONBLOCK);
	if (fd == -1) {
		fprintf(stderr, "Error opening %s\n", device);
		return 2;
	}
	codes[0] = scancode;
	codes[1] = KEY_SYSRQ;  /* from linux/input.h */
	if (ioctl(fd, EVIOCSKEYCODE, codes) == -1) {
		fprintf(stderr, "Error in EVIOCSKEYCODE ioctl\n");
		return 3;
	}

	return 0;
}
