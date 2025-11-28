#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER " | "

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)                                                             \
    X("", "~/.scripts/bluetooth_status", 1, 0)                                \
    X("",                                                                     \
      "amixer get Master | awk -F'[][]' 'END{if($4==\"off\"){print "          \
      "\"MUTE\"}else{print \"VOL \"$2}}'",                                    \
      1, 0)                                                                   \
    X("CPU", "top -bn1 | grep 'Cpu(s)' | awk '{print 100 - $8 \"%\"}'", 1, 0) \
    X("TEMP", "sensors | awk '/Package id 0:/ {print $4}'", 5, 0)             \
    X("MEM", "free -h --giga | awk '/Mem:/ {print $3 \"/\" $2}'", 5, 0)       \
    X("IP", "ip -4 addr show wlan0 | awk '/inet / {print $2}' | cut -d/ -f1", \
      10, 0)                                                                  \
    X("", "date '+%a %b %d, %Y %H:%M'", 1, 0)

#endif  // CONFIG_H
