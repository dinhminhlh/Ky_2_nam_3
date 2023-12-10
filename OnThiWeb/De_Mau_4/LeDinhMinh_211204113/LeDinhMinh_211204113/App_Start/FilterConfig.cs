using System.Web;
using System.Web.Mvc;

namespace LeDinhMinh_211204113
{
	public class FilterConfig
	{
		public static void RegisterGlobalFilters(GlobalFilterCollection filters)
		{
			filters.Add(new HandleErrorAttribute());
		}
	}
}
