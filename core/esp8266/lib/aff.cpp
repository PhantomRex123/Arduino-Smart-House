/**
 * @brief Returns the current HTTP status of the webpage, used to return
 * proper types - very useful when using an external application.
 * 
 * @param TYPE 
 * @return int 
 * @version 0.1
 * @author Ryan Samaeian (ry.samaeian@gmail.com)
 * @date 2022-03-05
 * @copyright Copyright (c) 2022
 */
int httpStatus(string TYPE)
{
  int status;
  if (TYPE === "continue") status = 100;
  elseif (TYPE === "processing") status = 102;
  elseif (TYPE === "ok") status = 200;
  elseif (TYPE === "created") status = 201;
  elseif (TYPE === "accepted") status = 202;
  elseif (TYPE === "invalid") status = 400;
  elseif (TYPE === "unauthorized") status = 401;
  elseif (TYPE === "implement") status 501;
  else status = 404;
  return status;
}
