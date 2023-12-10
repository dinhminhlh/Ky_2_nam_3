using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using De_Thi_Mau_2023.Models.Entities;
namespace De_Thi_Mau_2023.Controllers
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
            Model1 db = new Model1 ();
            List<LoaiHang> listLoai = db.LoaiHang.ToList();
            return PartialView("LeDinhMinh_Header", listLoai);
        }
        public ActionResult RenderProduct()
        {
			Model1 db = new Model1();
			List<HangHoa> listHang = db.HangHoa.Where(h => h.Gia >= 100).ToList();
            return PartialView("LeDinhMinh_Main", listHang);
		}
        public ActionResult RenderProductByCatId(int CatId)
        {
			Model1 db = new Model1();
			List<HangHoa> listHang = db.HangHoa.Where(h => h.MaLoai >= CatId).ToList();
			return PartialView("LeDinhMinh_Main", listHang);
        }
        public ActionResult Create()
        {
			Model1 db = new Model1();
			ViewBag.MaLoai = new SelectList(db.LoaiHang, "MaLoai", "TenLoai");
            return View();
        }
        [HttpPost]
        public ActionResult Create(HangHoa hang) 
        {
            if(ModelState.IsValid)
            {
				Model1 db = new Model1();
				db.HangHoa.Add(hang);
				db.SaveChanges();
				return Redirect("Index");
			}
            else
            {
				Model1 db = new Model1();
				ViewBag.MaLoai = new SelectList(db.LoaiHang, "MaLoai", "TenLoai");
				return View();
            }
        }
    }
}