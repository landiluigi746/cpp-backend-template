#include "middlewares/JsonRequest.hpp"

void JsonRequest::before_handle(crow::request& req, crow::response& res, context& ctx)
{
    if (req.get_header_value("Content-Type") != "application/json")
    {
        res.code = crow::status::BAD_REQUEST;
        res.end("This route accepts only data in JSON format");
    }
}
