const express = require('express');
const app = express();
const jwt = require('jsonwebtoken');
const auth = require('./routes/auth')
const mongoose = require('mongoose')
const bp = require('body-parser')
app.use(bp.json())
const postRoutes=require('./routes/posts')
require('dotenv/config')
const Joi = require('@hapi/joi')
const verify=require('./routes/verifyToken')
require('dotenv/config')
app.use('/api/user', auth)
app.use('/api/posts',postRoutes)
app.use(express.json());
app.get('/access_data', verify, (req,res)=>{
    res.send('passed after next function')
})



mongoose.connect(process.env.mongoURI, { useNewUrlParser: true, useUnifiedTopology: true }, () => { console.log('connected to database') })



const PORT = 3000;
app.listen(PORT, '127.0.0.1', () => {
    console.log(`server started at port: ${PORT}`)
})
