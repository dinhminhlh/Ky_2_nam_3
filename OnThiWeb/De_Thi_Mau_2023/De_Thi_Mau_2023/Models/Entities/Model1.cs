using System;
using System.ComponentModel.DataAnnotations.Schema;
using System.Data.Entity;
using System.Linq;

namespace De_Thi_Mau_2023.Models.Entities
{
	public partial class Model1 : DbContext
	{
		public Model1()
			: base("name=LeDinhMinh_Context")
		{
		}

		public virtual DbSet<HangHoa> HangHoa { get; set; }
		public virtual DbSet<LoaiHang> LoaiHang { get; set; }
		public virtual DbSet<tblAccount> tblAccount { get; set; }

		protected override void OnModelCreating(DbModelBuilder modelBuilder)
		{
			modelBuilder.Entity<HangHoa>()
				.Property(e => e.Gia)
				.HasPrecision(18, 0);

			modelBuilder.Entity<LoaiHang>()
				.HasMany(e => e.HangHoa)
				.WithRequired(e => e.LoaiHang)
				.WillCascadeOnDelete(false);

			modelBuilder.Entity<tblAccount>()
				.Property(e => e.Username)
				.IsFixedLength();

			modelBuilder.Entity<tblAccount>()
				.Property(e => e.Password)
				.IsFixedLength();
		}
	}
}
