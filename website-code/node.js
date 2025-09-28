const express = require("express");
const { SerialPort } = require("serialport");       // Import SerialPort
const { ReadlineParser } = require("@serialport/parser-readline");
const cors = require("cors");

const app = express();
const PORT = 3000;

// Set the correct COM port (Windows: "COM3", Linux/Mac: "/dev/ttyUSB0")
const ARDUINO_PORT = "COM5";

const serialPort = new SerialPort({
  path: ARDUINO_PORT,
  baudRate: 115200,
});

const parser = serialPort.pipe(new ReadlineParser({ delimiter: "\n" }));

let dustbinLevel = "N/A";

// Read data from Arduino and store it
parser.on("data", (data) => {
  if (data.includes("Level:")) {
    dustbinLevel = data.split(":")[1].trim();
    console.log(`Dustbin Level: ${dustbinLevel} %`);
  }
});

app.use(cors());

// API endpoint to get the dustbin level
app.get("/level", (req, res) => {
  res.json({ level: dustbinLevel });
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});
