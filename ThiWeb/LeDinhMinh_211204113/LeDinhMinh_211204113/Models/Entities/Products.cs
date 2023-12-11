namespace LeDinhMinh_211204113.Models.Entities
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Products
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Products()
        {
            Comments = new HashSet<Comments>();
            OrderDetails = new HashSet<OrderDetails>();
        }

        [StringLength(10)]
        public string Id { get; set; }

        [Required]
        [StringLength(50)]
        public string Name { get; set; }
		[Column(TypeName = "numeric")]
		[RegularExpression(@"[1-9][0-9]*", ErrorMessage = "Must be a number")]
		[Range(100, 5000)]
		public double UnitPrice { get; set; }

        public string Image { get; set; }

        public bool Available { get; set; }

        public int CategoryId { get; set; }

        public string Description { get; set; }

        public int ProviderId { get; set; }

        public virtual Categories Categories { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Comments> Comments { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<OrderDetails> OrderDetails { get; set; }

        public virtual Providers Providers { get; set; }
    }
}
