const express = require("express"); 
const cors = require("cors");       
const app = express(); //Access Express framework
const port = 3000;

app.use(cors()); //Different ports solving
app.use(express.urlencoded({ extended: true })); // POST data format

let latestMoistureLevel = "No data received yet"; 

// Endpoint to receive POST data from the ESP32
app.post("/receive_data", (req, res) => {
  latestMoistureLevel = req.body.soil_moisture || "No data"; //Extract data from the request body:
  console.log("Received soil moisture data:", latestMoistureLevel); //Prints data to server console
  res.send("Data received"); // Respond to the ESP32
});

// Endpoint to handle GET requests for fetching the latest soil moisture data
app.get("/receive_data", (req, res) => {
  res.send(latestMoistureLevel); 
});

app.get("/", (req, res) => {
  res.send("Welcome to the Soil Moisture Server");
});

app.listen(port, () => {
  console.log(`Server running at http://172.20.10.2:${port}`);
});
