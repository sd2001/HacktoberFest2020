const express = require('express');
const app = express.Router();
app.use(express.json())
const verify = require('./verifyToken')

app.get('/', verify, (req, res) => {
    res.send(req.user)
})




module.exports = app;