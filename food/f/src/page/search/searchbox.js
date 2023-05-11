import React from "react";

import PropTypes from "prop-types";
import "./App.css";

const SearchBar = ({onChange, placeholder}) => {
    return (
      <div className="Search">
        <span className="SearchSpan">
         
        </span>
        <input
          className="SearchInput"
          type="text"
          onChange={onChange}
          placeholder={placeholder}
        />
      </div>
    );
  };
  

SearchBar.propTypes = {
  
  onChange: PropTypes.func.isRequired,
  
  placeholder: PropTypes.string.isRequired,
};

export default SearchBar;