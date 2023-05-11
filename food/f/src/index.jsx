import React from "react";
import ReactDOM from "react-dom/client";
import Data from "./page/search/App";
import Global from "./page/global/global";
import ErrorPage from './page/errorpage'
import Lc from './page/lc/lc'
import {
  createBrowserRouter,
  RouterProvider,
} from "react-router-dom";
import "./index.css";

const router = createBrowserRouter([
  {
    path: "/",
    element: <Global />,
    errorElement: <ErrorPage />,
  },
  {
    path: "/search",
    element: <Data />,
    errorElement: <ErrorPage />,
  },
  {
    path: "/lc",
    element: <Lc />,
    errorElement: <ErrorPage />,
  },

]);

ReactDOM.createRoot(document.getElementById("root")).render(
  <React.StrictMode>
    <RouterProvider router={router} />
  </React.StrictMode>
);