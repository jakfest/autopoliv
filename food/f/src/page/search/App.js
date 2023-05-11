import Card from'./box.js';
import './App.css';
import func from'./u.js'
import SearchBar from './searchbox.js'
import Fuse from "fuse.js";
import food from "./food.json";
import {useState} from 'react';
export default function Data() {
const [data, setData] = useState(food);

  const searchData = (pattern) => {
    if (!pattern) {
      setData(food);
      return;
    }

    const fuse = new Fuse(data, {
      keys: ["title", "author"],
    });

    const result = fuse.search(pattern);
    const matches = [];
    if (!result.length) {
      setData([]);
    } else {
      result.forEach(({item}) => {
        matches.push(item);
      });
      setData(matches);
    }
  };

  return (
   
    <div class="glavnoe">
      <div class="kategor">
      <div class="naz"><p>Категории</p></div>
      <div class="option1">
          <button onclick={func} class="dropbtn">Категории</button>
          
        </div>
        <div class="catolog 2"><p>класс 2</p></div>
        <div class="catolog 3"><p>класс 3</p></div>



        <div><div id="myDropdown" class="dropdown-content">
          <a href="https://www.google.com/">Категория1</a>
          <a href="https://www.google.com/">Категория2</a>
          <a href="https://www.google.com/">Категория3</a>
          <a href="https://www.google.com/">Категория4</a>
          <a href="https://www.google.com/">Категория5</a>
        </div></div>
        </div>
       
       



    <div class="menu">

        <div class="name"></div>
        <SearchBar placeholder="Поиск"  onChange={(e) => searchData(e.target.value)}/>  
        <div class="search1"></div>
        <div class="hz">
        <div className="Container">
        {data.map((item) => (
          <Card {...item} key={item.title} />
        ))}
      </div>
        
        </div>
  
      </div>
    
     

      
    </div>
    
  );
}
