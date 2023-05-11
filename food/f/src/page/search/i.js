const SearchBar = ({onChange, placeholder}) => {
  return (
    <div className="Search">
      <span className="Search2">
        
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
export default SearchBar;
