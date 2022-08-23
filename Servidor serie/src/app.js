const { SerialPort } = require('serialport')
const port = new SerialPort({
  path: 'COM3',
  baudRate: 9600,
  autoOpen: false,
})

port.open(function (err) {
  if (err) {
    return console.log('Error opening port: ', err.message)
  }

  sendData()
})

async function sendData() {
  port.write('I')
  port.write('0')   // add1
  port.write('2')   // add2
  port.write('0')   // func
  port.write('0')   // dat1
  port.write('E')   // dat2
  port.write('F')
}

// The open event is always emitted
port.on('open', function() {
  // open logic
})

async function delay() {
  await sleep(500)
}

function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}