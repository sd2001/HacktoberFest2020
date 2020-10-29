// jshint esversion:6

const mongoose=require("mongoose");

mongoose.connect("mongodb://localhost:27017/fruitsDB",{useNewUrlParser: true, useUnifiedTopology: true});

const fruitSchema = new mongoose.Schema({
    name: {
        type: String,
        // required: [true,"Why no fruit ?"],
    },
    rating: {
        type: Number,
        min: 1,
        max: 10
    },
    review: String
});

const Fruit = mongoose.model("Fruit",fruitSchema);

const fruit = new Fruit({
    
    rating: 7,
    review: "Pretty solid as a fruit."
});

const Pineapple= new Fruit({
    name: "Pineapple",
    rating:9,
    review: "Great Fruit"
});
// Pineapple.save();

const strawberry=new Fruit({
    name:"Strawberry",
    rating:9,
    review:"Mapro fruit"
});
strawberry.save();
const personSchema = new mongoose.Schema({
    name: String,
    age: Number,
    favouriteFruit: fruitSchema
});

const Person = mongoose.model("Person",personSchema);

const guy=new Person({
    name: "Amy",
    age:12,
    favouriteFruit: Pineapple
});

guy.save();

// Person.updateOne({name:"John"},{favouriteFruit:strawberry},function(err)
// {
//     if(err)
//     {
//         console.log(err);
//     }
//     else{
//         console.log("Updated John's list");
//     }
// });

// const kiwi=new Fruit({
//     name:"Kiwi",
//     rating:10,
//     review : "Best fruit"
// });
// const orange=new Fruit({
//     name:"Orange",
//     rating:4,
//     review : "Kinda sour"
// });
// const banana=new Fruit({
//     name:"Banana",
//     rating:3,
//     review : "Weird Texture"
// });

// Fruit.insertMany([kiwi,orange,banana],function(err)
// {
//     if(err)
//     {
//         console.log(err);
//     }
//     else{
//         console.log("Successfully added to fruitsDB");
//     }
// })

Fruit.find(function(err,fruits)
{
    if(err)
    {
        console.log(err);
    }
    else{
        mongoose.connection.close();
        fruits.forEach(function(element)
        {
            console.log(element.name);        
        })
    };
});


// Updating a specific document in MongoDB

// Fruit.updateOne({_id: "5ebc26bdcd47b5407c680697"},{name:"Peach"},function(err){
//     if(err)
//     {
//         console.log(err);
//     }
//     else{
//         console.log("Successfully updated ");
//     }
// });

// Deleting a specific document in MongoDB

// Fruit.deleteOne({name:"Peach"},function(err){
//     if(err)
//     {
//         console.log(err);
//     }
//     else{
//         console.log("Successfully deleted");
//     }
// });


//Deleting Persons collection

// Person.deleteMany({name:"John"},function(err){
//     if(err){
//         console.log(err);
//     }
//     else{
//         console.log("Deleted successfully");
//     }
// });