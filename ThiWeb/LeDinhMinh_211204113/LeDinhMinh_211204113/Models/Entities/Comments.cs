namespace LeDinhMinh_211204113.Models.Entities
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Comments
    {
        public int Id { get; set; }

        [Required]
        [StringLength(200)]
        public string ComContent { get; set; }

        public DateTime? CreateAt { get; set; }

        [Required]
        [StringLength(10)]
        public string ProductId { get; set; }

        public int? Rate { get; set; }

        public virtual Products Products { get; set; }
    }
}
