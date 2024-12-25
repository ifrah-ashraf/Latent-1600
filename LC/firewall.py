def simple_firewall(packet):
    # List of trusted IPs and ports
    trusted_ips = ["192.168.1.100"]
    trusted_ports = [80, 443]  # HTTP and HTTPS

    # Check if the source IP is trusted and the destination port is allowed
    if packet["src_ip"] in trusted_ips:
        if packet["dst_port"] in trusted_ports:
            return True
    return False


# List of sample packets
packets = [
    {"src_ip": "192.168.1.100", "dst_ip": "192.168.1.200", "dst_port": 80},
    {"src_ip": "192.168.1.101", "dst_ip": "192.168.1.200", "dst_port": 80},
    {"src_ip": "192.168.1.100", "dst_ip": "192.168.1.200", "dst_port": 22},
]

# Process each packet through the firewall
for packet in packets:
    if simple_firewall(packet):
        print(f"Packet allowed: {packet}\n")
    else:
        print(f"Packet blocked: {packet}")
