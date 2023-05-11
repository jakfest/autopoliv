import React from "react";
import PropTypes from "prop-types";
import "./index";

const Card = (props) => {
  return (
    <div className="CardWrapper">
      <div className="ColImg">
        <img className="Img" src={props.image} alt={props.title} />
      </div>
      <div className="ColDetail">
        <div className="Header">
          <div className="BookTitle">{props.title}</div>
        </div>
        <div className="Description">{props.author}</div>
        <a className="Link" href={props.url}>
          Узнать больше
        </a>
      </div>
    </div>
  );
};

Card.propTypes = {
  /**
   *  Image
   */
  image: PropTypes.string.isRequired,
  /**
   * Title
   */
  title: PropTypes.string.isRequired,
  /**
   * Author
   */
  author: PropTypes.string.isRequired,
  /**
   * Url
   */
  url: PropTypes.string.isRequired,
};

export default Card;