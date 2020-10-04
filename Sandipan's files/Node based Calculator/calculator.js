const express = require('express');
const app = express();
const bodyParser= require("body-parser");

app.use(bodyParser.urlencoded({extended: true}));

app.get('/bmicalculator', function(req, res){
  res.sendFile(__dirname+"/bmiCalculator.html");
});

app.post("/bmicalculator",function(req, res){
	console.log(req.body);
	var x=Number(req.body.weight);
	var y=Number(req.body.height);
	var z=x/(y*y);
	res.send("The calculated BMI is: " +z);
})

app.listen(3000, function(){
  console.log("App listening at localhost:3000");
})