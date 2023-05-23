const SerialPort = require('serialport');
const http = require('http');

const express = require('express');
const cors = require('cors');

const app = express();
app.use(cors());

const parsers = SerialPort.parsers;
const parser = new parsers.Readline({ delimiter: '\r\n' });

const port = new SerialPort('/dev/ttyUSB1', {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});
port.pipe(parser);

const server = http.createServer(app); // Pass the express app to the server

app.get('/data', (req, res) => {
    res.writeHead(200, { 'Content-Type': 'application/json' });

    const onDataReceived = (data) => {
        try {
            const jsonData = JSON.parse(data);
            const lpgConcentration = jsonData.lpg;
            const coConcentration = jsonData.co;
            const smokeConcentration = jsonData.smoke;
            const responseData = {
                lpg: lpgConcentration,
                co: coConcentration,
                smoke: smokeConcentration
            };

            res.end(JSON.stringify(responseData));
            parser.off('data', onDataReceived); // Remove the event listener after responding
        } catch (error) {
            console.error('Error parsing data:', error);
            res.writeHead(500, { 'Content-Type': 'text/plain' });
            res.end('Internal Server Error');
        }
    };

    parser.on('data', onDataReceived);
});

server.listen(3000, () => console.log('Server is running on port 3000'));

// Error handling for the SerialPort and parser
port.on('error', (error) => {
    console.error('SerialPort error:', error);
});

parser.on('error', (error) => {
    console.error('Parser error:', error);
});