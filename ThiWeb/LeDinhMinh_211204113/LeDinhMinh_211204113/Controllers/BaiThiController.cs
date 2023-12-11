using LeDinhMinh_211204113.Models.Entities;
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
		public ActionResult RenderProduct()
		{
			Model1 db = new Model1();
			List<Products> listHang = db.Products.OrderByDescending(h => h.ProviderId).Take(6).ToList();
			return PartialView("MainRight", listHang);
		}

		public ActionResult TimKiem(string keyword)
		{
			Model1 db = new Model1();
			var sp = db.Products.AsQueryable();

			if (!string.IsNullOrEmpty(keyword))
			{
				sp = sp.Where(l => l.Name.ToLower().Contains(keyword.ToLower()));
				ViewBag.keyword = keyword;
			}
			return PartialView("MainRight", sp.ToList());
		}

		public ActionResult Create()
		{
			Model1 db = new Model1();
			ViewBag.ProvideId = new SelectList(db.Products, "ProvideId", "Name");
			return View();
		}
		[HttpPost]
		public ActionResult Edit(Products hang)
		{
			Model1 db = new Model1();
			db.Products.Add(hang);
			db.SaveChanges();
			// chuyen huong ve index
			return Redirect("Index");
		}
		public ActionResult Edit(Products hangHoa)
		{
			if (ModelState.IsValid)
			{
				Model1 db = new Model1();
				db.Products.Add(hangHoa);
				db.SaveChanges();
				return Redirect("Index");
			}
			else
			{
				Model1 db = new Model1();
				ViewBag.MaLoai = new SelectList(db.Products, "ProductId", "Name");
				return View();
			}
		}
	}
}