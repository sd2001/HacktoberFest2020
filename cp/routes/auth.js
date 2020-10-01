const express = require('express');
const app = express.Router();
const User = require('../model/User');
const Joi = require('@hapi/joi')
const bcrypt=require('bcryptjs')
const jwt=require('jsonwebtoken')
const { registerValidation,loginValidation } = require('../validation')

const schema = Joi.object({
    name: Joi.string().min(3).required(),
    email: Joi.string().min(10).required(),
    password: Joi.string().min(5).required()
});

app.post('/register', async (req, res) => {
    const { error } = registerValidation(req.body)
    const validation = schema.validate(req.body)
    //res.send(validation)  

    const emailExist=await User.findOne({email:req.body.email});
    if(emailExist) return res.status(401).send('email already exists')

    const salt=await bcrypt.genSalt(10);
    const hashedPassword=await bcrypt.hash(req.body.password,salt);

    /* if (validation.value == req.body)
         res.send(valiation)
 
     else
         res.send(validation.error.details[0].message)*/
    const user = new User({
        name: req.body.name,
        email: req.body.email,
        password: hashedPassword
    });
    try {
        const savedUser = await user.save();
        res.send(savedUser)
    }
    catch (err) {
        res.send(err)
    }
})

app.post('/login',async (req,res)=>{
   const {error}=loginValidation(req.body);
   if(error) return res.status(400).send(error)

   const user=await User.findOne({email:req.body.email});
   if(!user) return res.status(401).send('email is not found')


   const validPass=await bcrypt.compare(req.body.password,user.password)
   if(!validPass) return res.status(400).send('Invalid Password')

   const token=jwt.sign({_id:user._id,email:user.email,name:user.name},process.env.TOKEN_SECRET)
   res.header('auth-token',token).send(token);

   //res.send('logged in')
})

module.exports = app;