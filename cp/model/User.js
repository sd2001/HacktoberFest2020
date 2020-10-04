const mongoose=require('mongoose')

const userSchema=mongoose.Schema({
    
    email:{
        type:String,required:true
    },
    password:{
        type:String,
        required:true,
        max:1024,
        min:6
    },
    date:{
        type:Date,
        default:Date.now()
    }
})
module.exports=mongoose.model('hola peeps',userSchema);