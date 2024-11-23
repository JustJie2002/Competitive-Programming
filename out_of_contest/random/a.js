
function videoResolution(devices, bandwidths) {
    const ans = [];

    devices.forEach((device, index) => {
        let [a, ...b] = device.split("_");
        b = b.join("_");
        let bandwidth = bandwidths[index];

        if (a === "phone") {
            bandwidth = Math.min(bandwidth, 6);
        } else if (a === "tablet") {
            bandwidth = Math.min(bandwidth, 8);
        } else if (a === "screen") {
        } else {
            throw new Error("Invalid device type");
        }

        if (bandwidth === 0) {
            ans.push(`${b}:0p`);
        } else if (bandwidth <= 2) {
            ans.push(`${b}:360p`);
        } else if (bandwidth <= 4) {
            ans.push(`${b}:480p`);
        } else if (bandwidth <= 6) {
            ans.push(`${b}:720p`);
        } else if (bandwidth <= 8) {
            ans.push(`${b}:1080p`);
        } else {
            ans.push(`${b}:4k`);
        }
    });

    return ans;
}
