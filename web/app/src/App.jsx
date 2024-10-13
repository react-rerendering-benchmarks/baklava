import { memo } from "react";
import { useState } from 'react';
import './style.css';
const App = memo(function App() {
  console.log(window.globalCount++);
  return <>
    <h1>Baklava TD Web Game</h1> 
   </>;
});
export default App;