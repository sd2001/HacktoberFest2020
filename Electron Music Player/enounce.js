const electron = require('electron');
const url = require('url');
const path = require('path');
const $ = require('jquery');
const { app, BrowserWindow } = electron;


app.on('ready', () => {

    var tinyWindow = new BrowserWindow({
        width: 300,
        height: 400,
        frame:false,
        autoHideMenuBar: true,
        webPreferences: {nodeIntegration :true}
    });

    var mainWindow = new BrowserWindow({
        autoHideMenuBar: true,
        width:300,
        height:400,
        frame:true,
        resizable: true,
        webPreferences: { nodeIntegration: true }
    });

    setTimeout(() => {
        tinyWindow.close();

        //Garbage Collection Do not Remove

        tinyWindow = null;

        //Garabage Collection Ends Here
        mainWindow.loadURL(url.format({
            pathname: path.join(__dirname, 'html/index.html'),
            protocol: 'file:',
            slashes: true
        }));

    }, 1000);
    
    tinyWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'html/enounce.html'),
        protocol: 'file:',
        slashes: true
    }));

    //Quit App When Main Closed 

    mainWindow.on('closed', () => {
        app.quit();
    });
    
});
