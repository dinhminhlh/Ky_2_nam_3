using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using LeDinhMinh_211204113.Models.Entities;

namespace LeDinhMinh_211204113.Controllers
{
    public class BaiThiController : Controller
    {
        // GET: BaiThi
        public ActionResult Index()
        {
            return View();
        }
        public ActionResult RenderNav()
        {
            LeDinhMinh_Context db = new LeDinhMinh_Context();
            List<NavItems> listLoai = db.NavItems.ToList();
            return PartialView("LeDinhMinh_Header", listLoai);
        }

    }
}